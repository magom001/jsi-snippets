import * as React from 'react';

import { StyleSheet, View, Text, Button } from 'react-native';

export default function App() {
  const [count, setCount] = React.useState(0);

  React.useEffect(() => {
    (global as any).testThread().then((n: number) => {
      console.log('value', n);
      setCount(n);
    });
  }, [setCount]);

  return (
    <View style={styles.container}>
      <Text>Result: {(global as any).helloWorld()}</Text>
      <Text>Click count: {count}</Text>
      <Button onPress={() => setCount(count + 1)} title="button">
        <Text>Click me</Text>
      </Button>
      <Button
        onPress={() =>
          (global as any).testThread().then((n: number) => {
            console.log('xxx', n);
            setCount(n);
          })
        }
        title="test button"
      >
        <Text>Special button</Text>
      </Button>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    flexDirection: 'column',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
